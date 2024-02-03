#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_HP()
{
	Identifier = "DEFAULT_PT_HP";
	Name = "H-p";
	Colour = 0x4063FF_rgb;
	MenuVisible = 0;
	MenuSection = SC_ATOM;
	Enabled = 1;

	Advection = 0.4f;
	AirDrag = 0.04f * CFDS;
	AirLoss = 0.94f;
	Loss = 0.95f;
	Collision = -0.1f;
	Gravity = 0.3f;
	Diffusion = 0.00f;
	HotAir = 0.000f * CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 1;

	DefaultProperties.temp = R_TEMP - 295.15f + 273.15f;
	DefaultProperties.state = 2;
	HeatConduct = 251;
	Description = "Powder Hydrogen.";

	Properties = TYPE_PART;

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
	if (parts[i].state == 1)
		sim->part_change_type(i, x, y, PT_HS);
	return 0;
}