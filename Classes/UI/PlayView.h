#import <UIKit/UIKit.h>
@protocol PlayViewDelegate <NSObject>
- (void)playPressed;
@end
@interface PlayView : UIView
@property (nonatomic, weak) id<PlayViewDelegate> delegate;
- (IBAction)playPressed:(id)sender;
@end
