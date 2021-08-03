USE monitoria;

CREATE TABLE Aluno (
    ra INT PRIMARY KEY,
    nome VARCHAR(45),
    senha VARCHAR(20)
);

CREATE TABLE Monitor (
    monitorID INT,
    ra INT,
    nome VARCHAR(45),
    senha VARCHAR(20),
    email VARCHAR(45),
    disciplinaID INT,
    PRIMARY KEY (monitorID, ra)
);

CREATE TABLE Horario (
    horarioID INT,
    monitorID INT,
    diaSemana BIT(7),
    inicio TIME,
    fim TIME,
    PRIMARY KEY (horarioID, monitorID)
);

CREATE TABLE Disciplina (
    disciplinaID INT,
    codigo VARCHAR(10),
    nome VARCHAR(45),
    departamento VARCHAR(10),
    PRIMARY KEY (disciplinaID)
);

CREATE TABLE Orientador (
    ra INT,
    senha VARCHAR(20),
    PRIMARY KEY (ra)
);

CREATE TABLE Agendamento (
    alunoID INT,
    horarioID INT,
    PRIMARY KEY (alunoID, horarioID)
);


ALTER TABLE Monitor ADD CONSTRAINT fk_DisciplinaID FOREIGN KEY (disciplinaID) REFERENCES Disciplina(disciplinaID);