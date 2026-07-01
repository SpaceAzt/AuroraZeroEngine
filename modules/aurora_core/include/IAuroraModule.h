#pragma once

class IAuroraModule {
public:
	virtual ~IAuroraModule() = default;

	virtual bool Initialize() = 0;

	virtual void Update() = 0;

	virtual void Shutdown() = 0;
};
