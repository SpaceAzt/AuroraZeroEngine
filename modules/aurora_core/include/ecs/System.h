#pragma once

/******************************************************************************
 * Aurora Engine
 *
 * File:
 *      System.h
 *
 * Description:
 *      Base class for all ECS systems.
 ******************************************************************************/

class System {
public:
	virtual ~System() = default;

	virtual void Update() = 0;
};

protected:

// -------------------------------------------------------------------------
// TODO(v0.4):
// Add system priorities and execution order.
//
// Planned features:
// - Update Priority
// - Fixed Update
// - Late Update
// - Parallel Update
// -------------------------------------------------------------------------

};
