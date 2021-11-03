#ifndef BUILDER_H
#define BUILDER_H
class Builder {
public:
	virtual void BuildPart() = 0;
	virtual ~Builder() = default;
};
#endif
