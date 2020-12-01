import React, { useState, useEffect } from 'react';
import { Text, View, StyleSheet, FlatList } from 'react-native';
import * as Location from 'expo-location';
import {TextInput, Button} from "react-native-paper";

function computeDistance(lat1, lon1, lat2, lon2) 
{
  var R = 6371; // km
  var dLat = toRad(lat2-lat1);
  var dLon = toRad(lon2-lon1);
  var lat1 = toRad(lat1);
  var lat2 = toRad(lat2);

  var a = Math.sin(dLat/2) * Math.sin(dLat/2) +
    Math.sin(dLon/2) * Math.sin(dLon/2) * Math.cos(lat1) * Math.cos(lat2); 
  var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a)); 
  var d = R * c;
  return d*1000;
}

// Converts numeric degrees to radians
function toRad(Value) 
{
    return Value * Math.PI / 180;
}

export default function App() {
  const [location, setLocation] = useState(null);
  const [callOnce,setCallOnce] = useState(true);
  const [curLocation, setCurLocation] = useState(null);
  const [prevLocation, setPrevLocation] = useState(null);
  const [distances,setDistances] = useState([]);
  
  const [totalDistance,setTotalDistance] = useState(0);
  
  const [itv,setItv] = useState(10000);
  const [disIgnore,setDisIgnore]=useState(10);//if less than this, ignore 

  const [errorMsg, setErrorMsg] = useState(null);
  const getLocation = async()=> {
    let { status } = await Location.requestPermissionsAsync();
    if (status !== 'granted') {
      setErrorMsg('Permission to access location was denied');
    }
    let location = await Location.getCurrentPositionAsync({});
    setLocation(location);

  };
  useEffect(() => {
   getLocation();
  }, []);
  useEffect(() => {
    console.log("New Interval: " + itv);    
  }, [itv]);
  
  useEffect(() => {
    console.log("Shortest Distance: " + disIgnore);    
  }, [disIgnore]);
useEffect(()=>{
  // console.log(location);
  
  setPrevLocation(curLocation);
  setCurLocation(location);
  //setCurPrevLocations(location,curPrevLocations==null?null:curPrevLocations["curLocation"])
 if(callOnce){
  console.log("ITV: " + itv);
  setTimeout(()=>getLocation(),itv);
  // setCallOnce(false);
 }
},[location]);
useEffect(()=>{
 
 
  if(curLocation && prevLocation){
    // console.log(prevLocation["coords"]["latitude"],prevLocation["coords"]["longitude"],curLocation["coords"]["latitude"],curLocation["coords"]["longitude"]);
    let curDistance = computeDistance(prevLocation["coords"]["latitude"],prevLocation["coords"]["longitude"],curLocation["coords"]["latitude"],curLocation["coords"]["longitude"]);
    console.log("Distance: " , curDistance);
    setDistances([...distances,curDistance]); 
    if(curDistance>disIgnore){
      setTotalDistance(totalDistance+curDistance);
    }
  }

},[curLocation,prevLocation]);


  let text = 'Waiting..';
  if (errorMsg) {
    text = errorMsg;
  } else if (location) {
    text = JSON.stringify(location);
  }

  return (
    <View style={styles.container}>
   <TextInput
      label="Interval"
      // value={itv}
      onChangeText={text => setItv(parseInt(text))}
    />
    
   <TextInput
      label="Shortest Distance"
      // value={disIgnore}
      onChangeText={text => {setDisIgnore(parseInt(text));
        console.log(disIgnore+1);
        
        
        }}
    />
    <Button onPress={()=>{
      setDistances([]);
      setTotalDistance(0);
    }}><Text>Reset</Text></Button>
     <FlatList
        data={distances}
        renderItem={({item})=>{
          return(item!=0?<View style={{width:"90%",paddingVertical:20,backgroundColor:"#5f5",borderColor:"black",borderWidth:1}}>

              <Text style={{textAlign:"center"}}>{item<disIgnore?item + "(Not counted)":item}</Text>
              <Text style={{textAlign:"center"}}>Total Distance: {totalDistance}</Text>

            </View>
            :null)
        }}
        keyExtractor={item => item.id}
      />
      
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    padding:50,
    flex: 1,
  },
});