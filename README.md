# aes128_cmac
An aes_128_cmac algorithm implementation

##Introduction
At the beginning, My need is construct a packct that sent from a LoRaWAN node, so I need to calculate the mic(message integrity code).
It uses a algorithm called aes128_cmac (RFC4493) according to the specification of LoRaWAN 1.0.1

So I extracted the code from gateway to calculate mic.

##How to use it?
You just need call function `LoRaMacJoinComputeMic` with a mic variable, when computation is done, all we need is in `mic`.
