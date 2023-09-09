// Once ESPNow is successfully Init, we will register for recv CB to
// get recv packer info
esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
esp_now_register_recv_cb(OnDataRecv);
}
void loop(){
// Access the variables for each board
int board1r = boardsStruct[0].r;
int board1a = boardsStruct[0].a;
int board2r = boardsStruct[1].r;
int board2a = boardsStruct[1].a;
int board3r = boardsStruct[2].r;
int board3a = boardsStruct[2].a;
int avg =0
int board1avg = 0;
int board2avg = 0;
int board3avg = 0;
int ctr1=1;int ctr2=1;int ctr3=1;
rev=0;
//deg is the new variable
if( deg>=0 && deg<=120){

Serial.print("1 ");
Serial.print(board1r);
Serial.print(" ");
Serial.print(board1a);
Serial.print(" ");
board1avg=(board1avg+board1r)/ctr1;
ctr1++;
}
else if( deg>120 && deg<=240){
Serial.print("2 ");
Serial.print(board2r);
Serial.print(" ");
Serial.print(board2a);
Serial.print(" ");
board2avg=(board2avg+board2r)/ctr2;
ctr2++;
}
else if( deg>240 && deg<360){
Serial.print("3 ");
Serial.print(board3r);
Serial.print(" ");
Serial.print(board3a);
//Serial.print(" ");
LOCALISATION USING WIFI RSSI VALUES 12
board3avg=(board3avg+board3r)/ctr3;
ctr3++;
}
if(deg==360){
avg= (board1avg+board2avg+board3avg)/3;
board1avg=0;
board2avg=0;
board3avg=0;
ctr1=0;
ctr2=0;
ctr3=0;
}
if(avg==0){
Serial.print("wait");
}
else{
Serial.print("Final:");
Serial.print(avg);
}
Serial.println();
}
