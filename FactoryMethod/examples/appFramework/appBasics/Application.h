#ifndef APPLICATION_H
#define APPLICATION_H
class Document;
class Application
{
	Document *m_pDocument;
public:
	void New();
	void Open();
	void Save();
};
#endif
