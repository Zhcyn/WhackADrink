#ifndef ah_retain
#if __has_feature(objc_arc)
#define ah_retain self
#define ah_dealloc self
#define release self
#define autorelease self
#else
#define ah_retain retain
#define ah_dealloc dealloc
#define __bridge
#endif
#endif
#ifndef ah_weak
#import <Availability.h>
#if (__has_feature(objc_arc)) && \
((defined __IPHONE_OS_VERSION_MIN_REQUIRED && \
__IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_5_0) || \
(defined __MAC_OS_X_VERSION_MIN_REQUIRED && \
__MAC_OS_X_VERSION_MIN_REQUIRED > __MAC_10_7))
#define ah_weak weak
#define __ah_weak __weak
#else
#define ah_weak unsafe_unretained
#define __ah_weak __unsafe_unretained
#endif
#endif
#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif
extern NSUInteger const iRateAppStoreGameGenreID;
extern NSString *const iRateErrorDomain;
static NSString *const iRateMessageTitleKey = @"iRateMessageTitle";
static NSString *const iRateAppMessageKey = @"iRateAppMessage";
static NSString *const iRateGameMessageKey = @"iRateGameMessage";
static NSString *const iRateCancelButtonKey = @"iRateCancelButton";
static NSString *const iRateRemindButtonKey = @"iRateRemindButton";
static NSString *const iRateRateButtonKey = @"iRateRateButton";
typedef enum
{
    iRateErrorBundleIdDoesNotMatchAppStore = 1,
    iRateErrorApplicationNotFoundOnAppStore,
    iRateErrorApplicationIsNotLatestVersion
}
iRateErrorCode;
@protocol iRateDelegate <NSObject>
@optional
- (void)iRateCouldNotConnectToAppStore:(NSError *)error;
- (void)iRateDidDetectAppUpdate;
- (BOOL)iRateShouldPromptForRating;
- (void)iRateUserDidAttemptToRateApp;
- (void)iRateUserDidDeclineToRateApp;
- (void)iRateUserDidRequestReminderToRateApp;
@end
@interface iRate : NSObject
#ifdef __i386
{
    @private
    NSUInteger _appStoreID;
    NSUInteger _appStoreGenreID;
    NSString *_appStoreCountry;
    NSString *_applicationName;
    NSString *_applicationVersion;
    NSString *_applicationBundleID;
    NSUInteger _usesUntilPrompt;
    NSUInteger _eventsUntilPrompt;
    float _daysUntilPrompt;
    float _usesPerWeekForPrompt;
    float _remindPeriod;
    NSString *_messageTitle;
    NSString *_message;
    NSString *_cancelButtonLabel;
    NSString *_remindButtonLabel;
    NSString *_rateButtonLabel;
    NSURL *_ratingsURL;
    NSURL *_giftURL;
    BOOL _useAllAvailableLanguages;
    BOOL _disableAlertViewResizing;
    BOOL _promptAgainForEachNewVersion;
    BOOL _onlyPromptIfLatestVersion;
    BOOL _onlyPromptIfMainWindowIsAvailable;
    BOOL _promptAtLaunch;
    BOOL _verboseLogging;
    BOOL _previewMode;
    id<iRateDelegate> __ah_weak _delegate;
    id _visibleAlert;
    int _previousOrientation;
    BOOL _currentlyChecking;
}
#endif
+ (iRate *)sharedInstance;
@property (nonatomic, assign) NSUInteger appStoreID;
@property (nonatomic, assign) NSUInteger appStoreGenreID;
@property (nonatomic, copy) NSString *appStoreCountry;
@property (nonatomic, copy) NSString *applicationName;
@property (nonatomic, copy) NSString *applicationVersion;
@property (nonatomic, copy) NSString *applicationBundleID;
@property (nonatomic, assign) NSUInteger usesUntilPrompt;
@property (nonatomic, assign) NSUInteger eventsUntilPrompt;
@property (nonatomic, assign) float daysUntilPrompt;
@property (nonatomic, assign) float usesPerWeekForPrompt;
@property (nonatomic, assign) float remindPeriod;
@property (nonatomic, copy) NSString *messageTitle;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *cancelButtonLabel;
@property (nonatomic, copy) NSString *remindButtonLabel;
@property (nonatomic, copy) NSString *rateButtonLabel;
@property (nonatomic, assign) BOOL useAllAvailableLanguages;
@property (nonatomic, assign) BOOL disableAlertViewResizing;
@property (nonatomic, assign) BOOL promptAgainForEachNewVersion;
@property (nonatomic, assign) BOOL onlyPromptIfLatestVersion;
@property (nonatomic, assign) BOOL onlyPromptIfMainWindowIsAvailable;
@property (nonatomic, assign) BOOL promptAtLaunch;
@property (nonatomic, assign) BOOL verboseLogging;
@property (nonatomic, assign) BOOL previewMode;
@property (nonatomic, strong) NSURL *ratingsURL;
@property (nonatomic, strong) NSURL *giftURL;
@property (nonatomic, strong) NSDate *firstUsed;
@property (nonatomic, strong) NSDate *lastReminded;
@property (nonatomic, assign) NSUInteger usesCount;
@property (nonatomic, assign) NSUInteger eventCount;
@property (nonatomic, readonly) float usesPerWeek;
@property (nonatomic, assign) BOOL declinedThisVersion;
@property (nonatomic, readonly) BOOL declinedAnyVersion;
@property (nonatomic, assign) BOOL ratedThisVersion;
@property (nonatomic, readonly) BOOL ratedAnyVersion;
@property (nonatomic, ah_weak) id<iRateDelegate> delegate;
- (BOOL)shouldPromptForRating;
- (void)promptForRating;
- (void)promptIfNetworkAvailable;
- (void)openRatingsPageInAppStore;
- (void)openGiftAppPageInAppStore;
- (void)logEvent:(BOOL)deferPrompt;
- (void)getAppStoreID;
@end
