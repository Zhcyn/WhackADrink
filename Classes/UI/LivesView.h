#import <UIKit/UIKit.h>
@interface LivesView : UIView
@property (nonatomic, assign) NSInteger numberOfLives;
@property (nonatomic, assign, readonly) NSInteger currentLives;
- (void)removeLife;
@end
