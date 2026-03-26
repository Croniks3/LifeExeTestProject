#include "LifeExeTestProjectEditor.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"

#define LOCTEXT_NAMESPACE "FLifeExeTestProjectEditorModule"

IMPLEMENT_MODULE(FLifeExeTestProjectEditorModule, LifeExeTestProjectEditor)

void FLifeExeTestProjectEditorModule::StartupModule()
{
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

    TSharedRef<FPropertySection> Section = PropertyModule.FindOrCreateSection(
        "TestMovementActor",
        "ConfigData",
        LOCTEXT("ConfigData", "ConfigData"));

    Section->AddCategory("ConfigData");
    PropertyModule.NotifyCustomizationModuleChanged();
}

void FLifeExeTestProjectEditorModule::ShutdownModule()
{
    if(FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
    {
        FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

        PropertyModule.RemoveSection("TestMovementActor", "ConfigData");
        PropertyModule.NotifyCustomizationModuleChanged();
    }
}

#undef LOCTEXT_NAMESPACE