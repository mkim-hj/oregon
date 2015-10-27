//
//  ViewController.m
//  Oregon
//
//  Created by Maruchi Kim on 10/22/15.
//  Copyright © 2015 Maruchi Kim. All rights reserved.
//

#import "ViewController.h"
#import "AutomaticAdapter/AutomaticAdapter.h"
#import "ExternalAccessory/ExternalAccessory.h"
@import AUTAPIClient;
@import AFNetworking;

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UITextField *passwordText;
@property (weak, nonatomic) IBOutlet UITextField *usernameText;
@property (readwrite, nonatomic, strong) AUTClient *client;

@end

@implementation ViewController

ALELM327Session *currentSession = NULL;

static NSArray* getAttachedDevices() {
    EAAccessoryManager* accessoryManager = [EAAccessoryManager sharedAccessoryManager];
    if (accessoryManager) {
        return [accessoryManager connectedAccessories];
        //NSLog(@"ConnectedAccessories = %@", connectedAccessories);
    }
    return NULL;
}

static void getELMSession() {
    ALAutomaticAdapter * myAutomaticAdapter;
    NSArray* connectedDevices = getAttachedDevices();
    for (id device in connectedDevices) {
        myAutomaticAdapter = [device asAutomaticAdapter];
        if (myAutomaticAdapter) {
            break;
            // The EAAccessory is an Automatic Adapter.  Use this interface to
            // gain access to its engine data as shown below...
        }
    }
    
    [myAutomaticAdapter
     openAuthorizedSessionForAutomaticClient:@"1544288664bb7debe2de"
     allowingUserInteraction:YES
     onStatus:^(ALAuthStatus inAuthStatus, NSError *inError) {
         
         // Monitor authentication status and handle any errors here...
         NSLog(@"onStatus");
         
     }
     onAuthorized:^(ALELM327Session *inSession, NSString *inGreeting) {
         
         // This block is called if authentication succeeds.  The ALELM327Session can now
         // be used to communicate with the adapter and access engine data.  For example:
         NSLog(@"Succeeded");
         currentSession = inSession;
         //         [inSession sendLine:@"01 00" onResponse:^(NSString *inCommand, NSString *inResponse, NSError *inError) {
         //             // Check inError and use inResponse here...
         //         }];
         
         // Retain inSession to continue using it after this block returns.
     }
     onClosed:^(NSError *inError) {
         NSLog(@"Session Ended");
         // This block is called when the session ends (unless it was detached as
         // shown below)
         
     }];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    UIView *passwordPadding = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 5, 20)];
    UIView *usernamePadding = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 5, 20)];

    //Format text boxes
    [_passwordText setBorderStyle:UITextBorderStyleNone];
    _passwordText.layer.borderWidth = 0.5;
    _passwordText.layer.borderColor = [UIColor colorWithRed:0.565 green:0.608 blue:0.643 alpha:1].CGColor;
    _passwordText.leftView = passwordPadding;
    _passwordText.leftViewMode = UITextFieldViewModeAlways;
    
    [_usernameText setBorderStyle:UITextBorderStyleNone];
    _usernameText.layer.borderWidth = 0.5;
    _usernameText.layer.borderColor = [UIColor colorWithRed:0.565 green:0.608 blue:0.643 alpha:1].CGColor;
    _usernameText.leftView = usernamePadding;
    _usernameText.leftViewMode = UITextFieldViewModeAlways;
    
    self.client = [[AUTClient alloc] initWithClientID:@"1544288664bb7debe2de" clientSecret:@"9a1da50fa231b8fb077ba575dee0f1b6ac50ec20"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)loginButtonPressed:(id)sender {
    // Login
    [[[[[self.client
         authenticateWithUsername:_usernameText.text
         password:_passwordText.text
         scopes:AUTClientAuthorizationScopesTrip | AUTClientAuthorizationScopesLocation]
       flattenMap:^RACStream *(id value) {
           return [self.client authenticateLegacyWithUsername:_usernameText.text password:_passwordText.text];
       }]
      logAll]
      deliverOnMainThread]
     subscribeError:^(NSError *error) {
         UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Authentication Failed."
                                                         message:@"Please check your username and password and try again."
                                                        delegate:nil
                                               cancelButtonTitle:@"OK"
                                               otherButtonTitles:nil];
         [alert show];
     } completed:^{
//         [self performSegueWithIdentifier:@"loginSegue" sender:self];
         UIStoryboard *mainStoryboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
         UIViewController *dashboardController = [mainStoryboard instantiateViewControllerWithIdentifier:@"DashboardViewController"]; 
         [self presentViewController:dashboardController animated:YES completion:nil];
         
     }];
}

@end
