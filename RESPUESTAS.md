# RESPUESTAS

## Pregunta 3 — ¿Qué utilidad tiene utilizar tecnologías como git, en especial una plataforma como GitHub, como repositorio para su proyecto? ¿De qué manera agrega valor al desarrollo en conjunto de 3 o más personas?

**Resumen:** Git (sistema de control de versiones distribuido) y GitHub (plataforma colaborativa sobre Git) permiten trabajo paralelo seguro, **historial trazable**, **revisión por pares (pull requests)**, **ramificación/merge eficientes**, **resolución de conflictos** y **automatización del flujo de trabajo**. En equipos de 3+ personas esto reduce fricciones, mejora la calidad del código y acelera entregas.

### 1) Beneficios de usar Git (DVCS)
- **Trabajo distribuido y offline**: cada integrante tiene el historial completo local, puede *commit/branch/merge* sin conexión y sincronizar después. Esto hace rápidas las operaciones y resiliente al fallo del servidor. [1][2][6]
- **Ramas baratas + merges eficientes**: facilita *feature branches* y flujos como *Git Flow*, apoyando desarrollo paralelo sin bloquear a otros. [2][6]
- **Historial y recuperación**: registro completo y confiable de cambios; fácil volver a estados anteriores. [5]
- **Escalabilidad en equipos**: DVCS mejora la colaboración en equipos grandes y geográficamente distribuidos. [4][6]

### 2) ¿Qué agrega GitHub específicamente?
- **Pull Requests (PRs) y *code reviews***: propuesta de cambios con discusión, *diffs* y aprobaciones requeridas antes de mezclar a la rama principal. [3][7][8]
- **Gestión de permisos y protección de ramas**: políticas para exigir *reviews* y validar *status checks* antes de *merge*. [3]
- **Comunicación integrada**: comentarios en líneas de código, conversación por cambio, historial de decisiones.
- **Visibilidad y trazabilidad**: quién cambió qué y cuándo; útil para auditoría y responsabilidad técnica. [9]
- **Ecosistema**: wikis, Issues, Projects y CI/CD (Actions) que automatiza pruebas y despliegues.

### 3) ¿Cómo mejora el trabajo en equipos de 3+ personas?
- **Paralelismo seguro**: cada integrante trabaja en su rama sin pisar a otros; luego integra por PR con *reviews* que elevan la calidad.
- **Menos conflictos y mejor resolución**: el *branching model* acota superficies de conflicto; cuando existen, Git soporta *merge tools* eficientes. [2]
- **Velocidad y calidad**: *reviews* obligatorias + integración frecuente reducen defectos y tiempos de entrega. [3][6]
- **Transparencia y responsabilidad**: *blame/log* y PRs documentan decisiones y autores, lo que mejora la coordinación. [9]
- **Onboarding y continuidad**: el historial y los PRs sirven como documentación viva; bajar/continuar el trabajo es más simple.

### 4) Flujo sugerido para su Tarea
1. **Ramas**: `main` protegida; ramas `feat/…`, `fix/…`, `docs/…` por persona/tarea.
2. **PRs con revisión**: al menos 1 aprobación; ejecutar pruebas antes de mezclar.
3. **Commits atómicos** y mensajes claros (*imperative mood*).
4. **Issues** para dividir el trabajo y asignar responsables; cierre automático con `Fixes #N`.
5. **README** y **RESPUESTAS.md** versionados; usar Releases para congelar la entrega.

---

### Fuentes
[1] GitLab — Ventajas de los DVCS.  
[2] Atlassian — *Why Git (branching, merges, feature workflow)*.  
[3] GitHub Docs — *About pull request reviews* (revisiones obligatorias).  
[4] GeeksforGeeks — CVCS vs DVCS (ventajas para equipos grandes).  
[5] Pro Git (git-scm.com) — Sobre control de versiones (recuperación/historial).  
[6] Atlassian — *What is Git* (DVCS, operaciones locales rápidas).  
[7] GitHub Docs — *About pull requests* (discusión y diffs).  
[8] GitHub Docs — *Reviewing proposed changes* (revisión de commits y archivos).  
[9] APHRC (2025) — Colaboración, transparencia y atribución con Git/GitHub.

> Referencias detalladas:
> - [1] https://about.gitlab.com/topics/version-control/benefits-distributed-version-control-system/  
> - [2] https://www.atlassian.com/git/tutorials/why-git  
> - [3] https://docs.github.com/articles/about-pull-request-reviews  
> - [4] https://www.geeksforgeeks.org/git/centralized-vs-distributed-version-control-which-one-should-we-choose/  
> - [5] https://git-scm.com/book/ms/v2/Getting-Started-About-Version-Control  
> - [6] https://www.atlassian.com/git/tutorials/what-is-git  
> - [7] https://docs.github.com/articles/about-pull-requests  
> - [8] https://docs.github.com/articles/reviewing-proposed-changes-in-a-pull-request  
> - [9] https://aphrc.org/wp-content/uploads/2025/06/Overcoming-challenges.pdf
