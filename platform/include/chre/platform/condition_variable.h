/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CHRE_PLATFORM_CONDITION_VARIABLE_H_
#define CHRE_PLATFORM_CONDITION_VARIABLE_H_

#include "chre/platform/mutex.h"
#include "chre/target_platform/condition_variable_base.h"
#include "chre/util/non_copyable.h"

namespace chre {

/**
 * Provides an implementation of a Condition Variable. The public API is
 * similar to std::condition_variable. ConditionVariableBase is subclassed here
 * to allow platforms to inject their own storage for their implementation.
 */
class ConditionVariable : private ConditionVariableBase,
                          public NonCopyable {
 public:
  /**
   * Allows the platform to do any condition variable initialization at
   * construction time.
   */
  ConditionVariable();

  /**
   * Allows the platform to do any condition variable deinitialization at
   * destruction time.
   */
  ~ConditionVariable();

  /**
   * Unblock one thread that is waiting on this condition variable.
   */
  void notify_one();

  /**
   * Causes the current thread to block until the condition variable is
   * notified. The provided mutex will be unlocked and the thread will be
   * blocked until the condition variable has notified. The mutex is relocked
   * prior to this function returning.
   *
   * @param The currently locked mutex.
   */
  void wait(Mutex& mutex);
};

}  // namespace chre

#include "chre/target_platform/condition_variable_impl.h"

#endif  // CHRE_PLATFORM_CONDITION_VARIABLE_H_
