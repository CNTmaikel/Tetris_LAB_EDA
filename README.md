# 🛠 Guía para Trabajar con Ramas en GitHub

Esta guía explica cómo tú y tu compañero pueden trabajar en un mismo repositorio de GitHub utilizando ramas para evitar conflictos y mantener un flujo de trabajo ordenado.

**Repositorio en GitHub:** [Tetris_LAB_EDA](https://github.com/CNTmaikel/Tetris_LAB_EDA.git)

---

## 🚀 1. Configurar el Repositorio
1. **Crea un repositorio en GitHub** o utiliza uno existente.
2. **Clónalo en tu computadora**:
   ```sh
   git clone https://github.com/CNTmaikel/Tetris_LAB_EDA.git
   ```
3. Entra en el directorio del repositorio:
   ```sh
   cd Tetris_LAB_EDA
   ```

---

## 🌿 2. Crear una Nueva Rama para Trabajar
Cada desarrollador debe trabajar en su propia rama para evitar conflictos.

1. **Verifica que estás en la rama principal** (`main` o `master`):
   ```sh
   git checkout main
   ```
2. **Descarga los últimos cambios del repositorio remoto**:
   ```sh
   git pull origin main
   ```
3. **Crea una nueva rama con un nombre descriptivo**:
   ```sh
   git checkout -b nombre-de-la-rama
   ```
   *Ejemplo:* Si estás trabajando en una nueva funcionalidad llamada "login":
   ```sh
   git checkout -b login-feature
   ```

---

## ✏️ 3. Hacer Cambios y Confirmarlos
Una vez realizadas las modificaciones, guárdalas y confírmalas:

1. Agrega los archivos modificados:
   ```sh
   git add .
   ```
2. Confirma los cambios con un mensaje explicativo:
   ```sh
   git commit -m "Descripción breve del cambio"
   ```

---

## 🔄 4. Subir los Cambios al Repositorio Remoto
Para guardar los cambios en el repositorio de GitHub:

1. Sube tu rama al repositorio remoto:
   ```sh
   git push origin nombre-de-la-rama
   ```
2. Ve a **GitHub** y verás una notificación para una nueva rama. Crea un **Pull Request (PR)** para solicitar que los cambios se integren en `main`.

---

## 🔀 5. Fusionar la Rama en `main`
1. Espera a que tu compañero revise y apruebe el Pull Request.
2. Una vez aprobado, haz **merge** de la rama en `main`.
3. Borra la rama si ya no la necesitas:
   ```sh
   git branch -d nombre-de-la-rama
   ```

---

## ⚠️ 6. Actualizar el Código antes de Hacer Nuevos Cambios
Antes de comenzar una nueva funcionalidad, asegúrate de tener la versión más reciente del código:

1. Cambia a la rama principal (`main`):
   ```sh
   git checkout main
   ```
2. Descarga los últimos cambios:
   ```sh
   git pull origin main
   ```
3. Crea una nueva rama y continúa trabajando.

---

## 🎯 Conclusión
- **Usa ramas** para evitar conflictos.
- **Siempre descarga los cambios más recientes antes de comenzar a trabajar.**
- **Utiliza Pull Requests** para integrar los cambios en `main` de manera segura.

Con este sistema, ¡podrás trabajar colaborativamente sin sobrescribir los cambios de los demás! 🚀
