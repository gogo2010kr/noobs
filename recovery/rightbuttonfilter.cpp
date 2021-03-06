#include "rightbuttonfilter.h"
#include <QMouseEvent>

/*
 *                                                                                                                                                                             
 * Initial author: Floris Bos                                                                                                                                                
 * Maintained by Raspberry Pi                                                                                                                                                
 *                                                                                                                                                                       
 * See LICENSE.txt for license details                                                                                                                                 
 *                                                                                                                                                                   
 */

/* Eats right button clicks */

RightButtonFilter::RightButtonFilter(QObject *parent) :
    QObject(parent)
{
}

bool RightButtonFilter::eventFilter(QObject *, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        if (mouseEvent->button() == Qt::RightButton)
            return true; /* Eat right mouse button clicks */
    }

    return false;
}
