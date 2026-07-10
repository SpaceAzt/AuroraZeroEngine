Design Rule #001
Every engine system implements IModule.

Design Rule #002
ModuleManager never owns modules.

Design Rule #003
AuroraCore communicates only with ModuleManager.

Design Rule #004
Managers never communicate directly with AuroraCore.

Design Rule #005
Each module owns only one subsystem.

Design Rule #006
Modules own their subsystem.

Design Rule #007
Every module owns its own tests, benchmarks and docs.

Design Rule #008
Every module exposes its own test runner.

Design Rule #009
Every bug gets a regression test.

Design Rule #010
Architecture → API → Tests → Implementation.

Design Rule #011
EngineContext is shared context, not a service locator.

Design Rule #012
AuroraCore never creates modules.
