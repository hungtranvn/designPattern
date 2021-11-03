#ifndef APPLICATION_H
#define APPLICATION_H
class Document;
class Application {
	Document* m_pDocument;
public:
	void New();
	void Open();
	void Save();
	virtual Document* Create(){return nullptr;}
};
#endif
