#include <stdio.h>
#include <stdint.h>
#include "aes.h"
#include "cmac.h"
#include "LoRaMacCrypto.h"
#include "utilities.h"


uint8_t LoRaMacBuffer[256] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0xFF,0xEE};
// uint8_t LoRaMacAppKey[] = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };
// macHdr = 0x00
// AppEui = 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08
// DevEui = 0x1F,0x1E,0x1D,0x1C,0x1B,0x1A,0x19,0x18
// Nonce  = 0x01,0x02
uint8_t LoRaMacAppKey[] =  { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C };

uint16_t LoRaMacBufferPktLen = 19;
uint32_t mic = 0;

int main(){
    
    printf("macHdr : %x\n",LoRaMacBuffer[0]);
    printf("AppEui : %x %x %x %x %x %x %x %x\n",LoRaMacBuffer[1],LoRaMacBuffer[2],LoRaMacBuffer[3],LoRaMacBuffer[4],LoRaMacBuffer[5],LoRaMacBuffer[6],LoRaMacBuffer[7],LoRaMacBuffer[8]);
    printf("DevEui : %x %x %x %x %x %x %x %x\n",LoRaMacBuffer[9],LoRaMacBuffer[10],LoRaMacBuffer[11],LoRaMacBuffer[12],LoRaMacBuffer[13],LoRaMacBuffer[14],LoRaMacBuffer[15],LoRaMacBuffer[16]);
    printf("LoRaMacDevNonce : %x %x\n",LoRaMacBuffer[17],LoRaMacBuffer[18]);

    LoRaMacJoinComputeMic( LoRaMacBuffer, LoRaMacBufferPktLen & 0xFF, LoRaMacAppKey, &mic );

    
    LoRaMacBuffer[LoRaMacBufferPktLen++] = mic & 0xFF;
    LoRaMacBuffer[LoRaMacBufferPktLen++] = ( mic >> 8 ) & 0xFF;
    LoRaMacBuffer[LoRaMacBufferPktLen++] = ( mic >> 16 ) & 0xFF;
    LoRaMacBuffer[LoRaMacBufferPktLen++] = ( mic >> 24 ) & 0xFF;

    printf("mic : %x %x %x %x\n",LoRaMacBuffer[19],LoRaMacBuffer[20],LoRaMacBuffer[21],LoRaMacBuffer[22]);

    printf("\n\n");
    printf("packet:\n");
    for(int i=0;i<23;i++){
        if(i%5 == 0) printf("\n");
        printf("%x ",LoRaMacBuffer[i]);
    }
    printf("\n");
    for(int i=0;i<23;i++)
        printf("%d ",LoRaMacBuffer[i]);
    printf("\n");
}
