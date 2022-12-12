//
// Created by Paul Walker on 6/10/22.
//

#ifndef CLAP_SAW_DEMO_EDITOR_H
#define CLAP_SAW_DEMO_EDITOR_H
#include "clap-saw-demo.h"
#include "imgui-clap-support/imgui-clap-editor.h"
#include <unordered_map>

namespace sst::clap_saw_demo
{

struct ClapSawDemoEditor : public imgui_clap_editor
{
    ClapSawDemo::SynthToUI_Queue_t &inbound;
    ClapSawDemo::UIToSynth_Queue_t &outbound;
    const ClapSawDemo::DataCopyForUI &synthData;
    std::function<void()> paramRequestFlush;

    ClapSawDemoEditor(ClapSawDemo::SynthToUI_Queue_t &, ClapSawDemo::UIToSynth_Queue_t &,
                      const ClapSawDemo::DataCopyForUI &, std::function<void()>);
    
    void addSliderForParam(clap_id pid, const char* label, float min, float max);
    void addSwitchForParam(clap_id pid, const char* label, bool reverse);
    void addRadioButtonForParam(clap_id pid, std::vector<std::pair<int, const char*>>);

    void onRender() override;
    void dequeueParamUpdates();

    std::unordered_map<clap_id, double> paramCopy;
    std::unordered_map<clap_id, bool> paramInEdit;
};

} // namespace sst::clap_saw_demo
#endif
