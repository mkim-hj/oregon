//
//  AUTLog.h
//  AUTAPIClient
//
//  Created by Eric Horacek on 7/17/15.
//  Copyright (c) 2015 Automatic Labs. All rights reserved.
//

@import AUTLogKit;

/// A context for logging URL requests.
extern AUTLogContext AUTLogContextURLRequests;

#define AUTLogURLRequestError(frmt, ...) AUTLogError(AUTLogContextURLRequests, frmt, ##__VA_ARGS__)
#define AUTLogURLRequestInfo(frmt, ...)  AUTLogInfo(AUTLogContextURLRequests, frmt, ##__VA_ARGS__)

/// A context for logging URL responses.
extern AUTLogContext AUTLogContextURLResponses;

#define AUTLogURLResponseError(frmt, ...) AUTLogError(AUTLogContextURLResponses, frmt, ##__VA_ARGS__)
#define AUTLogURLResponseInfo(frmt, ...)  AUTLogInfo(AUTLogContextURLResponses, frmt, ##__VA_ARGS__)

/// A context for logging events related to authentication.
extern AUTLogContext AUTLogContextAuthentication;

#define AUTLogAuthenticationError(frmt, ...) AUTLogError(AUTLogContextAuthentication, frmt, ##__VA_ARGS__)
#define AUTLogAuthenticationInfo(frmt, ...)  AUTLogInfo(AUTLogContextAuthentication, frmt, ##__VA_ARGS__)
