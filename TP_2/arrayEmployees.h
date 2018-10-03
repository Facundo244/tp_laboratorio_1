#ifndef arrayEmployees
#define arrayEmployees
#define VACIO -1
#define OCUPADO 0
#define BORRADO 1
#define TAM 1000


typedef struct
{
    int id;
    char name[24];
    char lastName[24];
    float salary;
    char sector[5];
    int isEmpty;

} sEmployee;

int mostrarListadoEmployees(sEmployee listadoEmployee[] , int tam);
/** \brief Muestra en una lista encolumnada los datos de cada empleado registrado
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return int
 *
 */

void menuEmployees(sEmployee listadoEmployee[] , int);
/** \brief Muestra el menu principal
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return void
 *
 */

int findEmployeeById(sEmployee listadoEmployee[] , int , int);
/** \brief Busca el ID de un empleado
 *
 * \param listaEmployee[] sEmployee
 * \return int
 *
 */

int initEmployees(sEmployee listadoEmployee[] , int );
/** \brief inicializa a todos los empleados en -1 osea en  VACIO
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return int
 *
 */
int addEmployee(sEmployee listadoEmployee[] , int );
/** \brief Carga data de empleados hasta que no haya espacio
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return int
 *
 */
void mostrarUnEmploye(sEmployee listadoEmployee);
/** \brief Permite mostrar un listado de un empleado
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return void
 *
 */
void employeeRemoveById(sEmployee listadoEmployee[], int tam );
/** \brief Permite remover un empleado que se habia registrado
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return void
 *
 */
int IdAuto(void);
/** \brief No muestra un ID automaticamente en orden creciente
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return int
 *
 */
void employeeModify(sEmployee listadoEmployee[] , int tam);
/** \brief Permite modificar algun parametro de un empleado ya sea nombre , apellido , salario y sector
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return void
 *
 */
void alphabeticallyOrderedByLastName(sEmployee listadoEmployee[] , int tam);
/** \brief Ordena alfabeticamente por Apellido
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return void
 *
 */

void alphabeticallyOrderedBySector(sEmployee listadoEmployee[] , int tam);
/** \brief Ordena alfabeticamente por Sector
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return void
 *
 */
void menuInformes(sEmployee listadoEmployee[] , int tam);
/** \brief Ordena alfabeticamente por Sector
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return void
 *
 */
void avarageSalary(sEmployee listadoEmployee[] , int tam);
/** \brief Calcula el promedio , total y el salario mayor que el promedio
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return void
 *
 */

int traerIndiceVacio(sEmployee listadoEmployee[] ,int tam);
/** \brief Busca un espacio vacio para almacenar datos
 *
 * \param listaEmployee[] sEmployee
 * \param tam int
 * \return int
 *
 */


#endif // arrayEmployees
