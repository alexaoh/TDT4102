# Questions to the tasks (SOLVED)

1. Meninga at Persom-objekter uten bil skal faile her? Pga nullptr? La inn en try-catch for at den fortsatt skal fungere. Virker som om poenget med oppgaven er å illustrere at man må ta forhåndsregler ved bruk av nullptr. 

> Poenget er å returne false dersom det er ingen seter, noe som naturligvis også er tilfellet dersom personen ikke har bil. 

2. Hvorfor må set med Meetings initialiseres både i .h og i .cpp? (oppg 3: Meetings-klassen)

> Den settes som static i klassen-deklarasjonen for å signalisere at den er felles for alle objekter. Dermed må den initialiseres i .cpp, for den kan ikke initialiseres i et objekt (siden den skal være felles). 

3. Hvorfor fungerer addParticipant? Se kommentar i koden! Compiler klager ikke på mangel av const heller! Dette synes jeg er veldig rart. 

> Jeg ser ingenting nå i ettertid som tislier at den ikke skulle fungert. 

4. [SOLVED] Operator-overlastinga til Campus fungerer, men føles ikke helt optimalt nå. Kunne definert map med Campus til string utenfor funskjonen (som et const-map), men fugerer slik det er nå også. 

5. Hvilke av source-filene er egt nødvendige å importere i MeetingWindow.h? Har importert mange!

> Trenger GUI.h for alle widgets og Window.h for Window-klassen. 

## Recommended theory (PPP):
```
PPP Chapter 16 and 17
