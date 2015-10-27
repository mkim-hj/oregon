//
//  AUTLegacyKeychain.h
//  AUTAPIClient
//
//  Created by Sylvain Rebaud on 10/21/15.
//  Copyright © 2015 Automatic Labs. All rights reserved.
//

@import Valet;

NS_ASSUME_NONNULL_BEGIN

/// A helper class that wraps the old AUTKeychain use for storing credentials
/// into the keychain. This object should only be linked and use to test
/// migration during Beta Testing. See T11509.
@interface VALValet (Legacy)
@end

NS_ASSUME_NONNULL_END
