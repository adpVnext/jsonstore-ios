/*
 *     Copyright 2016 IBM Corp.
 *     Licensed under the Apache License, Version 2.0 (the "License");
 *     you may not use this file except in compliance with the License.
 *     You may obtain a copy of the License at
 *     http://www.apache.org/licenses/LICENSE-2.0
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#import <Foundation/Foundation.h>

@interface JSONStoreSecurityUtils : NSObject

/**
 Generates a random string locally.
 @param bytes Number of bytes that is used to generate the random string
 @return The random string, nil if the operation fails
*/
+(NSString*) generateRandomStringWithBytes:(int) bytes;

/**
 Encrypts an NSString by using a key and an Initialization Vector (IV).
 @param key The key used for encryption
 @param text The text to encrypt
 @param iv The IV used for encryption
 @param covertBase64BeforeEncryptionFlag When true, convert to base64 before encrypting
 @return The encrypted text
*/
+(NSString*) _encryptWithKey:(NSString*) key
                    withText:(NSString*) text
                      withIV:(NSString*) iv
covertBase64BeforeEncryption:(BOOL) covertBase64BeforeEncryptionFlag;

/**
 Decrypts an NSString by using a key and an Initialization Vector (IV).
 @param key The key used for decryption
 @param ciphertext The encrypted text to decrypt
 @param iv The IV used for decryption
 @param decodeBase64AfterDecryption When true, decode base64 after decryption
 @return The decrypted text
 */
+(NSString*) _decryptWithKey:(NSString*) key
              withCipherText:(NSString*) ciphertext
                      withIV:(NSString*) iv
 decodeBase64AfterDecryption:(BOOL) decodeBase64AfterDecryption
         checkBase64Encoding:(BOOL) checkBase64Encoding;

/**
 Generates a key by using the PBKDF2 algorithm.
 @param pass The password that is used to generate the key
 @param salt The salt that is used to generate the key
 @param iterations The number of iterations that is passed to the key generation algorithm
 @return The generated key
*/
+(NSString*) generateKeyWithPassword: (NSString *) pass
                             andSalt: (NSString *) salt
                       andIterations: (NSInteger) iterations;

/**
 Encrypts text with a key.
 @param text The text to encrypt
 @param key The key used for encryption
 @param error Error
 @return An NSDictionary with the cipher text (ct), the IV (iv), the source (src) and the version (v).
 */
+(NSDictionary*) encryptText: (NSString*) text
                     withKey: (NSString*) key
                       error: (NSError**) error;

/**
 Decrypts a dictionary that contains: src (source), v (version), ct (cipher text) and the iv (initialization vector).
 @param ciphertext The encrypted text to decrypt
 @param key The key used for decryption
 @param encryptedObj NSDictionary that is returned from encryptText:withKey:error:
 @param error Error
 @return The decrypted text
 */
+(NSString*) decryptWithKey: (NSString*) key
              andDictionary:(NSDictionary*) encryptedObj
                      error: (NSError**) error;
@end
