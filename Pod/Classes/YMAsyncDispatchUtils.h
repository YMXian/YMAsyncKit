//
//  YMAsyncDispatchUtils.h
//  Pods
//
//  Created by 琰珂 郭 on 15/11/13.
//
//  Shortcuts to GCD functions

#import <Foundation/Foundation.h>

#import "YMAsyncBlock.h"

#pragma mark - GCD dispatch_async

/**
 *  Dispatch async a block on global queue
 *
 *  @param identifier global queue identifier, such as DISPATCH_QUEUE_PRIORITY_LOW
 *  @param block      block to queue
 */
extern void dispatch_async_global(long identifier, YMAsyncVoidBlock __nonnull block);

/**
 *  Dispatch async a block to global low priority queue
 *
 *  @param block block to queue
 */
extern void dispatch_async_low(YMAsyncVoidBlock __nonnull block);

/**
 *  Dispatch async a block to global high priority queue
 *
 *  @param block block to queue
 */
extern void dispatch_async_high(YMAsyncVoidBlock __nonnull block);

/**
 *  Dispatch async a block to main queue
 *
 *  @param block block to queue
 */
extern void dispatch_async_main(YMAsyncVoidBlock __nonnull block);

/**
 *  Dispatch sync a block to main queue
 *
 *  @param block block to queue
 */
extern void dispatch_sync_main(YMAsyncVoidBlock __nonnull block);

#pragma mark - GCD dispatch_main

/**
 *  Invoke the block if in main thread, else dispatch async to main queue
 *
 *  @param block block to queue
 */
extern void dispatch_async_main_alt(YMAsyncVoidBlock __nonnull block);

/**
 *  Invoke the block if in main thread, else dispatch sync to main queue
 *
 *  @param block block to queue
 */
extern void dispatch_sync_main_alt(YMAsyncVoidBlock __nonnull block);

#pragma mark - GCD dispatch_after

/**
 *  Dispatch a block after seconds on a queue
 *
 *  @param queue   the queue
 *  @param seconds delay in seconds
 *  @param block   block to queue
 */
extern void dispatch_after_seconds(dispatch_queue_t __nonnull queue, NSTimeInterval seconds, YMAsyncVoidBlock __nonnull block);

/**
 *  Dispatch a block after seconds on main queue
 *
 *  @param seconds delay in seconds
 *  @param block   block to queue
 */
extern void dispatch_main_after(NSTimeInterval seconds, YMAsyncVoidBlock __nonnull block);