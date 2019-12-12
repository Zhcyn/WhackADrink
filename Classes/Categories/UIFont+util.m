#import "UIFont+util.h"
@implementation UIFont (util)
+ (UIFont *)applicationFontWithSize:(CGFloat)size
{
    return [UIFont fontWithName:@"Helvetica-Light" size:size];
}
@end
