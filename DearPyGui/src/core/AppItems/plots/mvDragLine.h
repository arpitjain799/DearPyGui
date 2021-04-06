#pragma once

#include "mvTypeBases.h"

namespace Marvel {

	MV_REGISTER_WIDGET(mvDragLine, MV_ITEM_DESC_DEFAULT, StorageValueTypes::Float, 1);
	class mvDragLine : public mvFloatPtrBase
	{
	public:

		static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

		MV_APPITEM_TYPE(mvAppItemType::mvDragLine, add_drag_line)

		MV_START_EXTRA_COMMANDS
		MV_END_EXTRA_COMMANDS

		MV_START_GENERAL_CONSTANTS
		MV_END_GENERAL_CONSTANTS

		MV_START_COLOR_CONSTANTS
		MV_END_COLOR_CONSTANTS

		MV_START_STYLE_CONSTANTS
		MV_END_STYLE_CONSTANTS

	public:

		mvDragLine(const std::string& name, float default_value, const std::string& dataSource);

		void draw(ImDrawList* drawlist, float x, float y) override;

		void setExtraConfigDict(PyObject* dict) override;
		void getExtraConfigDict(PyObject* dict) override;
		bool isParentCompatible(mvAppItemType type) override;

	private:

		bool    m_show_label = true;
		mvColor m_color = mvColor(0.0f, 0.0f, 0.0f, -1.0f);
		float   m_thickness = 1.0f;
		bool    m_vertical = true;

	};

}
