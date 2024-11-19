void timer_init() {
    TCCR1B |= (1 << WGM12); // Modo CTC
    TCCR1B |= (1 << CS11);  // Prescaler 8
    OCR1A = 19999;          // Valor para generar un tick de 1 ms
    TIMSK1 |= (1 << OCIE1A); // Habilitar interrupción
}

ISR(TIMER1_COMPA_vect) {
    // Incrementa el contador de ticks
    system_tick++;
}
