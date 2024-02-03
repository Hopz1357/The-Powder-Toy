#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_HS()
{
	Identifier = "DEFAULT_PT_HS";
	Name = "H-s";
	Colour = 0x4063FF_rgb;
	MenuVisible = 0;
	MenuSection = SC_ATOM;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.90f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 100;

	DefaultProperties.temp = R_TEMP - 295.15f + 273.15f;
	DefaultProperties.state = 1;
	HeatConduct = 251;
	Description = "Solid Hydrogen.";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 14.01f;
	HighTemperatureTransition = PT_HL;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (parts[i].state == 2)
		sim->part_change_type(i, x, y, PT_HP);
	return 0;
}