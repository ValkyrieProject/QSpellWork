#include <QFile>

#include "SWEnums.h"

SWEnums::SWEnums()
{
    loadEnums();
}


SWEnums::~SWEnums()
{
}

void SWEnums::loadEnums()
{
    QFile xmlFile("data/enums.xml");
    xmlFile.open(QIODevice::ReadOnly);
    m_xmlData.setContent(&xmlFile);
    xmlFile.close();

    QDomNodeList enumNodes = m_xmlData.firstChild().childNodes();
    for (qint32 i = 0; i < enumNodes.count(); ++i)
    {
        QDomNodeList valuesNodes = enumNodes.item(i).toElement().childNodes();
        Enumerator enumerator;
        for (qint32 j = 0; j < valuesNodes.count(); ++j)
        {
            QDomElement valueElement = valuesNodes.item(j).toElement();
            if (valueElement.attribute("key").contains("0x"))
            {
                bool ok;
                enumerator[valueElement.attribute("key").toLongLong(&ok, 16)]= valueElement.attribute("value");
            }
            else
                enumerator[valueElement.attribute("key").toLongLong()]= valueElement.attribute("value");
        }
        m_enums[enumNodes.item(i).toElement().tagName()] = enumerator;
        
    }
}
