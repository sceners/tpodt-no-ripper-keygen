/**
Armadillo Key Creator by Mr. eXoDia...

TPoDT_LVL :
    -1: Unsigned

    00: Signed V2 Level 1
    01: Signed V2 Level 2
    02: Signed V2 Level 3
    03: Signed V2 Level 4

    10: Signed V3 Level 1
    11: Signed V3 Level 2
    12: Signed V3 Level 3
    13: Signed V3 Level 4
    14: Signed V3 Level 5
    15: Signed V3 Level 6
    16: Signed V3 Level 7
    17: Signed V3 Level 8
    18: Signed V3 Level 9

    20: Short V3 Level 1
    21: Short V3 Level 2
    22: Short V3 Level 3
    23: Short V3 Level 4
    24: Short V3 Level 5
    25: Short V3 Level 6
    26: Short V3 Level 7
    27: Short V3 Level 8
    28: Short V3 Level 9
    29: Short V3 Level 10

TPoDT_Y The number Y in hexadecimal format, don't forget ""
TPoDT_PVT The number Pvt in hexadecimal format, don't forget ""
TPoDT_SYM Symmetric key. Use 0x in the front for HEX, without 0x is decimal
TPoDT_OTH0-4 Otherinfo parameters, see the section down here for that
TPoDT_ABOUT Text to display in about box, don't forget ""
TPoDT_STATIC Text to display in the static control under the serial text box
TPoDT_TITLE Window title

--------------------------------------------------------------------------------

Otherinfo parameters. Use MakeDate.exe to generate otherinfo0 compatible dates.

otherinfo0: Expiration info (if expiration-in-key use MakeDate.exe to generate correct values);
otherinfo1: Number of copies; on how many machines this key may be installed.
otherinfo2: Lower 16 bits of extrainfo (Set to 3 if you want extrainfo to be 3)
otherinfo3: Higher 16 bits of extrainfo (Not used most of the times)
otherinfo4: Reserved for future expansion. MUST BE ZERO

Unused parameters MUST be set to ZERO!

Greetings,

Mr. eXoDia // T.P.o.D.T 2011
mr.exodia.tpodt@gmail.com
http://www.tpodt.com
*/

#define TPoDT_LVL  20
#define TPoDT_Y    "443B5C3A"
#define TPoDT_PVT  "413473DE"
#define TPoDT_SYM  "D7F7D801"
#define TPoDT_OTH0 0
#define TPoDT_OTH1 0
#define TPoDT_OTH2 0
#define TPoDT_OTH3 0
#define TPoDT_OTH4 0
#define TPoDT_ABOUT "Cracked by Mr. eXoDia // T.P.o.D.T 2011"
#define TPoDT_STATIC "Armadillo ShortV3 Level 1"
#define TPoDT_TITLE "Armada Tanks v1.0"


