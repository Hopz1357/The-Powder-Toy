#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);
static void create(ELEMENT_CREATE_FUNC_ARGS);

void Element::Element_ANTR()
{
	Identifier = "DEFAULT_PT_ANTR";
	Name = "ANTR";
	Colour = 0x646464_rgb;
	MenuVisible = 1;
	MenuSection = SC_PARTICLE;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 1.00f;
	Loss = 1.00f;
	Collision = -0.99f;
	Gravity = 0.0f;
	Diffusion = 0.2f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = -1;

	DefaultProperties.tmp = 1;
	HeatConduct = 0;
	Description = "Anti Neutrino.";

	Properties = TYPE_ENERGY|PROP_LIFE_DEC|PROP_LIFE_KILL_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &update;
	Graphics = &graphics;
	Create = &create;
}

static int update(UPDATE_FUNC_ARGS)
{
	auto& sd = SimulationData::CRef();
	auto& elements = sd.elements;
	for (auto rx = -2; rx <= 2; rx++)
	{
		for (auto ry = -2; ry <= 2; ry++)
		{
			auto r = pmap[y + ry][x + rx];
			if (!r)
				r = sim->photons[y + ry][x + rx];
			if (!r)
				continue;
			switch (TYP(r))
			{
			case PT_NTRI:
			{
				if ((parts[i].tmp == 1 && parts[ID(r)].tmp == 1) || (parts[i].tmp == 2 && parts[ID(r)].tmp == 2) || (parts[i].tmp == 3 && parts[ID(r)].tmp == 3))
				{
					auto n1 = sim->create_part(-1, x + rx, y + ry, PT_PHOT);
					auto n2 = sim->create_part(-1, x + rx, y + ry, PT_PHOT);
					float a1 = sim->rng.between(0, 359) * 3.14159f / 180.0f;
					float a2 = sim->rng.between(0, 359) * 3.14159f / 180.0f;
					sim->kill_part(i);
					sim->kill_part(ID(r));
					parts[n1].life = 50;
					parts[n2].life = 50;
					parts[n1].vx = 3.0f * cosf(a1);
					parts[n2].vx = 3.0f * cosf(a2);
					parts[n1].vy = 3.0f * sinf(a1);
					parts[n2].vy = 3.0f * sinf(a2);
				}
				break;
			}
			}
		}
	}
	return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
	if (cpart->tmp == 1)
	{
		*colr = 100;
		*colg = 100;
		*colb = 230;

		*firea = 50;
		*firer = 0;
		*fireg = 0;
		*fireb = 170;
	}
	if (cpart->tmp == 2)
	{
		*colr = 230;
		*colg = 100;
		*colb = 230;

		*firea = 50;
		*firer = 170;
		*fireg = 0;
		*fireb = 170;
	}
	if (cpart->tmp == 3)
	{
		*colr = 230;
		*colg = 100;
		*colb = 100;

		*firea = 50;
		*firer = 170;
		*fireg = 0;
		*fireb = 0;
	}

	*pixel_mode |= FIRE_BLEND;
	return 0;
}

static void create(ELEMENT_CREATE_FUNC_ARGS)
{
	float a = sim->rng.between(0, 359) * 3.14159f / 180.0f;
	sim->parts[i].life = sim->rng.between(250, 600);
	sim->parts[i].vx = 2.0f*cosf(a);
	sim->parts[i].vy = 2.0f*sinf(a);
}
