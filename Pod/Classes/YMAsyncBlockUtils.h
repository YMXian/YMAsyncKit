//
//  YMAsyncBlockUtils.h
//  Pods
//
//  Created by 琰珂 郭 on 15/11/13.
//
//

#import <Foundation/Foundation.h>

#import "YMAsyncBlock.h"

#pragma mark - Block manimulate

/**
 *  Create a block from inputBlock, no matter how many times outputBlock is invoked, inputBlock will be invoked once
 *
 *  @param inputBlock
 *
 *  @return outputBlock, returns YES if it is the first time invoked
 */
extern YMAsyncBOOLBlock __nonnull YMAsyncCreateOnceBlock(YMAsyncVoidBlock __nonnull inputBlock);

/**
 *  Create a block from inputBlock, inputBlock will be invoked once when outputBlock is invoked for a certain count
 *
 *  @param count      the count
 *  @param inputBlock the inputBlock
 *
 *  @return outputBlock, returns NSComparisonResult between target count and current counter
 */
extern YMAsyncCompareBlock __nonnull YMAsyncCreateAllBlock(NSUInteger count, YMAsyncVoidBlock __nonnull inputBlock);