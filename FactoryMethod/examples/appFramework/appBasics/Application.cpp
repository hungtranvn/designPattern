#include "Application.h"
#include "TextDocument.h"
void Application::New() {
	m_pDocument = new TextDocument{};
}
void Application::Open() {
	m_pDocument = new TextDocument{};
  m_pDocument->Read();
}
void Application::Save() {
	m_pDocument->Write();
}
