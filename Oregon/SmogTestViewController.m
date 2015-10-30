//
//  SmogTestViewController.m
//  Oregon
//
//  Created by Maruchi Kim on 10/28/15.
//  Copyright © 2015 Maruchi Kim. All rights reserved.
//

#import "SmogTestViewController.h"
#import "AutomaticAdapter/AutomaticAdapter.h"
#import "AppDelegate.h"

@interface SmogTestViewController ()
@property (weak, nonatomic) IBOutlet UIButton *nextButton;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicatorView;
@property (weak, nonatomic) IBOutlet UIButton *testingButton;
@property (weak, nonatomic) IBOutlet UIImageView *completedIcon;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *testRunningIndicator;

@end

@implementation SmogTestViewController

//ALELM327Session *currentSession = NULL;
NSTimer * myTimer;
int tryCount = 0;

static NSArray* getAttachedDevices() {
    EAAccessoryManager* accessoryManager = [EAAccessoryManager sharedAccessoryManager];
    if (accessoryManager) {
        return [accessoryManager connectedAccessories];
        //NSLog(@"ConnectedAccessories = %@", connectedAccessories);
    }
    return NULL;
}

- (void) getELMSession:(NSTimer *) timer {
    if (!_currentSession) {
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
        
        if (!myAutomaticAdapter) {
            //increment a counter
            tryCount++;
            NSLog(@"Attempted: %i", tryCount);
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
             _currentSession = inSession;
             [myTimer invalidate];
             [self.activityIndicatorView stopAnimating];
             [_nextButton setTitle: @"Next" forState:UIControlStateNormal];
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
}

-(void) getSmogStatus: (NSTimer *) timer {
    [_currentSession sendLine:@"AL SMOGOR" onResponse:^(NSString *inCommand, NSString *inResponse, NSError *inError) {
        if (!([inResponse isEqual: @"Smog in progress"])) {
            [myTimer invalidate];
            [self.testRunningIndicator stopAnimating];
            _completedIcon.hidden = NO;
            [_testingButton setTitle: @"Next" forState:UIControlStateNormal];
        }
        NSLog(@"RESPONSE: %@", inResponse);
    }];
}


- (void) pollLink {
    myTimer = [NSTimer scheduledTimerWithTimeInterval:1
                                               target:self
                                             selector:@selector(getELMSession:)
                                             userInfo:nil
                                              repeats:YES];
    [myTimer fire];
}

- (void) pollSmog {
    myTimer = [NSTimer scheduledTimerWithTimeInterval:2
                                               target:self
                                             selector:@selector(getSmogStatus:)
                                             userInfo:nil
                                              repeats:YES];
    [myTimer fire];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.activityIndicatorView startAnimating];
    
    // Start polling smog
    if ([self.restorationIdentifier isEqual: @"SmogRunningViewController"]) {
        _completedIcon.hidden = YES;
        NSLog(@"Polling Smog...");
        [self pollSmog];

    }
    
    //Link with Streaming SDK!
    if (!_currentSession) {
        NSLog(@"Called");
        [self pollLink];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)startTest:(id)sender {
    NSLog(@"here");
    if ([_nextButton.currentTitle  isEqual: @"Next"]) {
        [_currentSession sendLine:@"01 00" onResponse:^(NSString *inCommand, NSString *inResponse, NSError *inError) {
            // Check inError and use inResponse here...
            NSLog(@"Sending 0100");
            NSLog(@"%@", inResponse);
            NSLog(@"%@", inError);
            
            if ([inResponse  isEqual: @"NO DATA"]) {
                UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Unable to Read Port"
                                                                message:@"Please check to make sure your Link is plugged in firmly into the OBD portand try again."
                                                               delegate:nil
                                                      cancelButtonTitle:@"OK"
                                                      otherButtonTitles:nil];
                [alert show];
            } else {
                NSLog(@"Start Smog Test!");
                //Send AT Smog...
                [self performSegueWithIdentifier:@"toRunTest" sender:self];
            }
            
        }];
    } else {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Ignition Off"
                                                        message:@"Please check to make sure your car's ignition is on and try again."
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
        [alert show];
    }
}

- (IBAction)testCompleted:(id)sender {
    if ([_testingButton.currentTitle isEqual:@"Next"]) {
        [self performSegueWithIdentifier:@"toSuccess" sender:self];
    }
}


- (IBAction)exitPressed:(id)sender {
    [myTimer invalidate];
    AppDelegate * delegate = [[UIApplication sharedApplication] delegate];
    [delegate goToDashboard];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    ((SmogTestViewController *) [segue destinationViewController]).currentSession = _currentSession;
}


@end
