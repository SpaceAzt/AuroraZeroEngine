#include "AuroraApplication.h"

#include "AuroraCore.h"

bool AuroraApplication::Initialize() {
	AuroraCore &core = AuroraCore::Get();

	return core.Initialize();
}

void AuroraApplication::Update() {
	AuroraCore::Get().Update();
}

void AuroraApplication::Shutdown() {
	AuroraCore::Get().Shutdown();
}
