#ifndef DOCUMENT_H
#define DOCUMENT_H
class Document {
public: 
	virtual void Write() = 0 ;
	virtual void Read() = 0 ;
	virtual ~Document() = default ;
};
#endif
