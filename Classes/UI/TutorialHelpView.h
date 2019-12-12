#import <UIKit/UIKit.h>
@interface TutorialHelpView : UIView
@property (nonatomic, assign) CGFloat arrowWidth;
- (id)initWithText:(NSString *)text;
- (CGSize)sizeOfView;
@end
