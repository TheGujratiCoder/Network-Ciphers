AIM / OBJECTIVE :

Perform encryption, decryption using the following substitution techniques
	
 1) Ceaser cipher

 2) ROT-13

Discussion: 

The Caesar cipher is one of the earliest known and simplest ciphers. It is a type of substitution cipher in which each letter in the plaintext is 'shifted' a certain number of places down the alphabet. For example, with a shift of 1, A would be replaced by B, B would become C, and so on. The method is named after Julius Caesar, who apparently used it to communicate with his generals. More complex encryption schemes such as the Vigenere employ the Caesar cipher as one element of the encryption process. The widely known ROT13 'encryption' is simply a Caesar cipher with an offset of 13. The Caesar cipher offers essentially no communication security, and it will be shown that it can be easily broken even by hand.
To pass an encrypted message from one person to another, it is first necessary that both parties have the 'key' for the cipher, so that the sender may encrypt it and the receiver may decrypt it. For the caesar cipher, the key is the number of characters to shift the cipher alphabet.

First we translate all of our characters to numbers, 'a'=0, 'b'=1, 'c'=2, ... , 'z'=25. We can now represent the caesar cipher encryption function, e(x), where x is the character we are encrypting, as:

e(x)=(x+k)(mod 26)

Where k is the key (the shift) applied to each letter. After applying this function the result is a number which must then be translated back into a letter. The decryption function is :

e(x)=(x-k)(mod 26)

Program Execution:
Enter the PLAIN TEXT for Encryption:
     >information

Enter the CAESERKEY between 0 and 25:
     >7

ENCRYPTION

CIPHER TEXT :pumvythapvu

DECRYPTION

PLAIN TEXT :information

What's Rot13?

Rot13 is a simple "encryption" algorithm designed to make text illegible, but very easily "decrypted". It's used on USENET to post material that may be offensive - the reader has to choose to convert it back to plain text. Rot13 simply adds 13 to the value of each character, and wraps around back to "A" when it gets to "Z". So "A" becomes "N", "B" becomes "O", and "N" becomes "A". It works on both upper and lower case characters and leaves non-alphabetic characters as they were.

Questions for practise: 

1. Crack the following plaintext TRVJRI TZGYVIJ RIV HLZKV VRJP KF TIRTB

Ans ) Since we have to use Brute Force Method , we apply it for k=1 to 25 and theoriginal string produced is :

k=1 : SQUISH SYFXUHI QHU GKYJU UQIO JE SHQSA

k=2 : RPTIHR RXEWTGH PGT FJXIT TPHN ID RGHRZ

k=3 : QOSHGQ QWDVSGF OFS EIWHS SOGM HC QFGQY

k=4 : PNRGBP PUCURFE NFR DHVGR RNFL GB PFEPX

k=5 : OMQFAO OTBTRED MES CGUFMQ OMEK FA OEMOW

k=6 : NLPFZN NSAASDC LDR BFTFLP NLDB EZ NDLNV

k=7 : MKOEXM MRYZRDB KCQ AESYLO MKCA DY MCKMU

k=8 : LJNDWL LQXYQCA JBP ZDRXKN LJAZ CX LBJLT

k=9 : KIMCVK KPWXPBZ IAO YCQWJM KIZY BW KAIKS

k=10 : JHLBUJ JOVWQAY HZN XBPVIL JHXY AV JZJHR

k=11 : IGKATI INUVPHX GYM WAOUHK IGWX ZU IYIGQ

k=12 : HFJZSH HMTUOGW FXL VZNTGJ HFVW YT HXHFPS

k=13 : GIEYRG GLSTNFW EWK UYMSFI GEUZ XS GWGER

k=14 : FHDXQF FKRSMEV DVJ TXLRDH FDTY WR FVFDQ

k=15 : EGCPPE EJQRLEU CUI SWKQCG ECSX VQ EUECP

k=16 : DFBODD DIJQKDT BTH RVJPCF DBRW UP DTDBO

k=17 : CEAONC CHIPJCS ASG QUIOBE CASV TO SCASN

k=18 : BDZNMB BFGOIAB ZRF PTHNAD BZRQ SN RBAZM

k=19 : ACYMLA AEFNHZA YQE OSGMZC AQYP RM QAZYL

k=20 : ZBXLKZ ZDEMGYZ XPD NRFLYB ZPXO QL PZBXK

k=21 : YAWKJY YCDLFXY WOC MQEKXA YOWN PK OYAWJ

k=22 : XZVJIX XBCKEWX VNB LPDJJW XNVM OJ NXZVI

k=23 : WYUHIW WABJDVW UMA KOCIIU WMLU NI MWYUH

k=24 : VXTGHV VZAICUV TLZ JNBIHT VLKT MH LVXTG

k=25 : UWSFGU UYZHBTU SKY IMAHGS UKJS LG KUWSF

It looks like the correct shift value is 4, and the decrypted message is: "PROMPT PLEASE LET ME KNOW WHAT SHIFT."

2. What key do we need to make “CAESAR” become “MKOCKB”?

Ans ) We can subtract the ASCII values between two characters at the same position of the given strings . Since the difference between any of them is 12 , our encryption key is 12 .

3. What key do we need to make “CIPHER” become “SYFXUH”?

We can subtract the ASCII values between two characters at the same position of the given strings . Since difference between any of them is 16 , our encryption key is 16 .

4. Use the Caesar cipher to encrypt your first name .

Ans) Given key=3 my name in Casear Cipher text is ZDUDG DFKDVBD . 

5. How can we find the decryption key from the encryption key?

Ans) To find decryption key from the encryption key , we can use Brute Force Method to check whether the statement after decryption i.e after we subtract value from all characters , does the statement make sense . If statement makes sense then we have found the key else we continue our process .

Instruction: You need to take the input file of any name and generate the cipher text in the output file in any name
