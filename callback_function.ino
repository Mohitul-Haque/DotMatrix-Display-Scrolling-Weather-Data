//-----------------------Callback function-------------------------------------//

void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  
//-------------------------------------Getting config data---------------------//
  StaticJsonDocument<256> doc;
  deserializeJson(doc, payload, length);

   TMP = doc["TMP"];
   HUM = doc["HUM"];
   VOC = doc["VOC"];
  Serial.println(TMP);
  Serial.println(HUM);
  Serial.println(VOC);
//
//  if( did == "101"){
//      if(cmd == 1){
//        Serial.println("RESET");
//        client.publish("dev/res","success");
//        delay(1000);
//      }
//      else{
//        Serial.println("COMMAND INVALID");
//        client.publish("dev/res","failed");
//        delay(1000);
//      }
//  }
     
}//Callback ends
