//
//  YMAsyncBlock.h
//  Pods
//
//  Created by 琰珂 郭 on 15/11/13.
//
//  Basic block types used in YMAsyncKit.

#import <Foundation/Foundation.h>

#pragma mark - Basic block types

/**
 *  Block accept void, returns void
 */
typedef void (^YMAsyncVoidBlock) ();

/**
 *  Block accept void, returns BOOL
 *
 *  @return BOOL
 */
typedef BOOL (^YMAsyncBOOLBlock) ();

/**
 *  Block accept void, returns NSComparisonResult
 *
 *  @return NSComparisonResult
 */
typedef NSComparisonResult (^YMAsyncCompareBlock) ();

/**
 *  General purposed callback block
 *
 *  @param error error object if any error occured
 */
typedef void (^YMAsyncCallbackBlock) (NSError* __nullable error);

/**
 *  General purposed operation block, accept a YMAsyncCallbackBlock as input
 *
 *  @param callback YMAsyncCallbackBlock, shall be invoked when operation finished
 */
typedef void (^YMAsyncOperationBlock) (YMAsyncCallbackBlock __nonnull callback);

#pragma mark - Basic block macros

/**
 *  Invoke a block if block not nil
 *
 *  @param BLOCK block or nil
 *  @param ...   block arguments
 */
#define block_safe_invoke(BLOCK, ...)  if (BLOCK) { BLOCK(__VA_ARGS__); }