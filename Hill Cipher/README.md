AIM / OBJECTIVE :

To understand the Hill Cipher Encryption Algorithm

Hill cipher : 

Hill cipher is a polygraphic substitution cipher based on linear algebra.Each letter is represented by a number modulo 26. Often the simple scheme A = 0, B = 1, …, Z = 25 is used, 
but this is not an essential feature of the cipher. To encrypt a message, each block of n letters (considered as an n-component vector) is multiplied by an invertible n × n matrix, 
against modulus 26. To decrypt the message, each block is multiplied by the inverse of the matrix used for encryption.
The matrix used for encryption is the cipher key, and it should be chosen randomly from the set of invertible n × n matrices (modulo 26).

Input  : 

Plaintext: ACT

Key: GYBNQKURP

Output : Ciphertext: POH

We have to encrypt the message ‘ACT’ (n=3).

The key is ‘GYBNQKURP’ which can be written as the nxn matrix 

![image](https://github.com/TheGujratiCoder/Network-Ciphers/assets/127189365/d0dc9d98-bb3c-4f68-a4f8-9bfb6475d7d2)

The message ‘ACT’ is written as vector: 

![image](https://github.com/TheGujratiCoder/Network-Ciphers/assets/127189365/bfbb9a4e-c459-4c8d-a39b-6a75ca39f569)

The enciphered vector is given as: which corresponds to ciphertext of ‘POH’ 

![image](https://github.com/TheGujratiCoder/Network-Ciphers/assets/127189365/8488bc5c-69cf-45cc-8a91-fcbd0a88540a)

Decryption : 

To decrypt the message, we turn the ciphertext back into a vector, then simply multiply by the inverse matrix of the key matrix (IFKVIVVMI in letters).
The inverse of the matrix used in the previous example is:

![image](https://github.com/TheGujratiCoder/Network-Ciphers/assets/127189365/f9249835-d11c-460e-9cde-879494052038)
 
For the previous Ciphertext ‘POH’: which gives us back ‘ACT’. 

![image](https://github.com/TheGujratiCoder/Network-Ciphers/assets/127189365/4f2cdc69-cb32-4a0a-88cc-1e3b4e40a8b3)

Assume that all the alphabets are in upper case. 
