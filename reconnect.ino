//------------------------------------------------While client not conncected---------------------------------//



boolean reconnect() {

    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266-";
    clientId += String(random(0xffff), HEX);
  
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
           
      client.subscribe("dsiot/dbox/ws");
      delay(500);
    }else{     
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again");
//      mqttTryCounter++;
//      Serial.println(mqttTryCounter);
      // Wait 6 seconds before retrying
//      delay(5000); //timer control implemented
    }    
  return client.connected();
}// reconnect() ends
