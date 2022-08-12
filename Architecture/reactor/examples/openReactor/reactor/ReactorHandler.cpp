/*
 * ReactorHandler.cpp
 *
 *  Created on: 2020. 6. 26.
 *      Author: tys
 */

#include "ReactorHandler.h"
#include "Reactor.h"

using namespace reactor;

bool
ReactorHandler::set_timeout(const uint32_t &msec)
{
  if (reactor_ == nullptr)
    return false;

  return reactor_->set_timeout(this, msec);
}

void
ReactorHandler::unset_timeout()
{
  if (reactor_ == nullptr)
    return;

  reactor_->unset_timeout(this);
}

