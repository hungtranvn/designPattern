#ifndef DIRECTOR_H
#define DIRECTOR_H
class Builder;
class Director {
	Builder *builder;
public:
	Director(Builder* builder);
	void Construct( );
};
#endif
