/*

    Copyright (C) 2022 Nishant Mishra <https://github.com/NMrocks>

    This program is licensed under the GNU General Public License.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <QRandomGenerator>
#include <QString>
#include <QStringLiteral>

#include "generate.h"

static const QString alpha(QStringLiteral("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"));
static const QString num(QStringLiteral("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"));
static const QString sym(QStringLiteral("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*"));

QString generatePassword(QString charset, int len)
{
    if (charset == "Alphabets") {
        QString passwd = QStringLiteral("");
        for (int i=0; i<len; ++i)
        {
            passwd.append(alpha[QRandomGenerator::global()->bounded(52)]);
        }
        return passwd;
    }
    if (charset == "Alphabets + Numbers") {
        QString passwd = QStringLiteral("");
        for (int i=0; i<len; ++i)
        {
            passwd.append(num[QRandomGenerator::global()->bounded(62)]);
        }
        return passwd;
    }
    else {
        QString passwd = QStringLiteral("");
        for (int i=0; i<len; ++i)
        {
            passwd.append(sym[QRandomGenerator::global()->bounded(70)]);
        }
        return passwd;
    }
};
