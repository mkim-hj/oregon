//
//  AUTAPIClient.h
//  AUTAPIClient
//
//  Created by Robert Böhnke on 25/03/15.
//  Copyright (c) 2015 Automatic Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for AUTAPIClient.
FOUNDATION_EXPORT double AUTAPIClientVersionNumber;

//! Project version string for AUTAPIClient.
FOUNDATION_EXPORT const unsigned char AUTAPIClientVersionString[];

#import <AUTAPIClient/AFHTTPRequestSerializer+OAuth2.h>
#import <AUTAPIClient/AFOAuth2SessionManager.h>
#import <AUTAPIClient/RACSignal+AUTAuthenticationOperators.h>

#import <AUTAPIClient/VALValet+Automatic.h>
#import <AUTAPIClient/AUTAPIAddress.h>
#import <AUTAPIClient/AUTBase64Transformer.h>
#import <AUTAPIClient/AUTHexadecimalTransformer.h>
#import <AUTAPIClient/AUTClient+AUTAPIDevice.h>
#import <AUTAPIClient/AUTClient+AUTAPITrip.h>
#import <AUTAPIClient/AUTClient+AUTAPIUser.h>
#import <AUTAPIClient/AUTClient+AUTAPIVehicle.h>
#import <AUTAPIClient/AUTClient+AUTCredentialOperations.h>
#import <AUTAPIClient/AUTClient.h>
#import <AUTAPIClient/AUTAPIDevice.h>
#import <AUTAPIClient/AUTAPIFirmware.h>
#import <AUTAPIClient/AUTAPIFirmwareVersion.h>
#import <AUTAPIClient/AUTAPIVehicle.h>
#import <AUTAPIClient/AUTHTTPResponseCodes.h>
#import <AUTAPIClient/AUTLicensePlusBadge.h>
#import <AUTAPIClient/AUTLicensePlusBadgeState.h>
#import <AUTAPIClient/AUTLicensePlusCoachInvitation.h>
#import <AUTAPIClient/AUTLicensePlusPerson.h>
#import <AUTAPIClient/AUTLicensePlusProgram.h>
#import <AUTAPIClient/AUTLicensePlusProgramState.h>
#import <AUTAPIClient/AUTAPILocation.h>
#import <AUTAPIClient/AUTAPIObject.h>
#import <AUTAPIClient/AUTAPIPage.h>
#import <AUTAPIClient/AUTAPIPark.h>
#import <AUTAPIClient/AUTAPIParkTimer.h>
#import <AUTAPIClient/AUTAPIParkPhoto.h>
#import <AUTAPIClient/AUTRequest.h>
#import <AUTAPIClient/AUTAPITrip.h>
#import <AUTAPIClient/AUTAPITripChunk.h>
#import <AUTAPIClient/AUTAPIUser.h>
#import <AUTAPIClient/AUTAPIVehicleState.h>
#import <AUTAPIClient/AUTAPIMobileVehicle.h>
#import <AUTAPIClient/AUTLog.h>
#import <AUTAPIClient/AUTAPIRealTimeEvent.h>
#import <AUTAPIClient/AUTAPISettingsObject.h>
#import <AUTAPIClient/AUTAPISettingsPage.h>
#import <AUTAPIClient/AUTAPISettingsGroup.h>
#import <AUTAPIClient/AUTAPISettingsItem.h>
#import <AUTAPIClient/AUTAPISettingsToggleItem.h>
#import <AUTAPIClient/AUTClient+AUTAPISettings.h>

#import <AUTAPIClient/AUTLicensePlusClient.h>
#import <AUTAPIClient/AUTLicensePlusClient+AUTSession.h>
#import <AUTAPIClient/AUTLicensePlusClient+AUTLicensePlus.h>

#import <AUTAPIClient/AUTClient+Legacy.h>
#import <AUTAPIClient/AUTAPILegacyResponse.h>
#import <AUTAPIClient/AUTClient+AUTLegacyCredentialOperations.h>
#import <AUTAPIClient/AUTLegacyCredential.h>
#import <AUTAPIClient/AUTAPIEncryptionData.h>
#import <AUTAPIClient/AUTClient+AUTAPIEncryptionData.h>
#import <AUTAPIClient/AUTAPILegacyVehicle.h>
#import <AUTAPIClient/AUTClient+AUTAPILegacyVehicle.h>
#import <AUTAPIClient/AUTAPIClientErrors.h>
#import <AUTAPIClient/AUTClient+AUTTripUpload.h>
#import <AUTAPIClient/AUTClient+AUTAPIRealTimeEvent.h>
#import <AUTAPIClient/AUTAPILegacyLinkInfo.h>
#import <AUTAPIClient/AUTClient+AUTAPILegacyLinkInfo.h>

#import <AUTAPIClient/AUTClient+AUTAPIMobileVehicle.h>

