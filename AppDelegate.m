#import "AppDelegate.h"
#import "GameCenterManager.h"
@implementation AppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    NSString *analyticsKey = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"AnalyticsKey"];
    [[GameCenterManager sharedInstance] initialiseManager];
    return YES;
}
- (void)applicationWillResignActive:(UIApplication *)application
{
}
- (void)applicationDidEnterBackground:(UIApplication *)application
{
}
- (void)applicationWillEnterForeground:(UIApplication *)application
{
}
- (void)applicationDidBecomeActive:(UIApplication *)application
{
}
- (void)applicationWillTerminate:(UIApplication *)application
{
}
@end
