#import <Foundation/Foundation.h>
#define kNotificationAchievementEarned @"AchievementEarned"
#define kNotificationAchievementProgress @"AchievementProgress"
@class GKLeaderboard;
@interface GameCenterManager : NSObject
@property (atomic, readonly) BOOL userAuthenticated;
@property (atomic, readonly) BOOL leaderboardLoaded;
@property (atomic, readonly) BOOL achievementsLoaded;
@property (nonatomic, assign) BOOL useCustomAchievementInterface;
@property (nonatomic, assign) BOOL showAchievementProgress;
+ (GameCenterManager *)sharedInstance;
- (void)initialiseManager;
- (void)authenticateLocalUser;
- (UIViewController *)leaderboardViewControllerForID:(NSString *)leaderboardID;
- (GKLeaderboard *)leaderboardForID:(NSString *)leaderboardID friendsOnly:(BOOL)friendsOnly;
- (void)reportScore:(NSInteger)score forLeaderboardID:(NSString *)leaderboardID;
- (UIViewController *)achievementController;
- (void)resetAchievementProgress;
- (void)completeAchievement:(NSString *)achievementID;
- (void)updateAchievementProgress:(NSString *)achievementID percentComplete:(CGFloat)percentage;
@end
