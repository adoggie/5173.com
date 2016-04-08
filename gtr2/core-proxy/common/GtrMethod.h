#pragma once

struct gtr_ctx_param
{
	int timeout;
	int tries;
	int sleep;
};

class GtrMethod	:	public gtr_ctx_param
{
public:
	GtrMethod(void);
	~GtrMethod(void);
};
