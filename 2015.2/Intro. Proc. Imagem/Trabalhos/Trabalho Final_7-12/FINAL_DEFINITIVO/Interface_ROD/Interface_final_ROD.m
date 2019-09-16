function varargout = Interface_final_ROD(varargin)
% INTERFACE_FINAL_ROD MATLAB code for Interface_final_ROD.fig
%      INTERFACE_FINAL_ROD, by itself, creates a new INTERFACE_FINAL_ROD or raises the existing
%      singleton*.
%
%      H = INTERFACE_FINAL_ROD returns the handle to a new INTERFACE_FINAL_ROD or the handle to
%      the existing singleton*.
%
%      INTERFACE_FINAL_ROD('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in INTERFACE_FINAL_ROD.M with the given input arguments.
%
%      INTERFACE_FINAL_ROD('Property','Value',...) creates a new INTERFACE_FINAL_ROD or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Interface_final_ROD_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Interface_final_ROD_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to imgify the response to help Interface_final_ROD

% Last imgified by GUIDE v2.5 25-Nov-2015 23:26:14

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Interface_final_ROD_OpeningFcn, ...
                   'gui_OutputFcn',  @Interface_final_ROD_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Interface_final_ROD is made visible.
function Interface_final_ROD_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Interface_final_ROD (see VARARGIN)

% Choose default command line output for Interface_final_ROD
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Interface_final_ROD wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Interface_final_ROD_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

% --- Executes on button press in Fechar.
function Fechar_Callback(hObject, eventdata, handles)
% hObject    handle to Fechar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
clear all, close all

% --- Executes on button press in Acertou.
function Acertou_Callback(hObject, eventdata, handles)
% hObject    handle to Acertou (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
vazio = vazio + 1;
set (findobj(gcf, 'Tag', 'Teste'), 'String', num2str(vazio), 'ForegroundColor', 'red');

% --- Executes on button press in Errou.
function Errou_Callback(hObject, eventdata, handles)
% hObject    handle to Errou (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Iniciar.
function Iniciar_Callback(hObject, eventdata, handles)
% hObject    handle to Iniciar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    %%  Limpeza da Área de Trabalho
        clear web, clc


    %%  Disponibilizando as Imagens Modelos
        %   Modelo para o gesto: Pedra
            img = imread('../Imagens Modelo/modelo_0.jpg');
            axes (handles.ModPedra), imshow(img);
        %   Modelo para o gesto: Papel
            img = imread('../Imagens Modelo/modelo_1.jpg');
            axes (handles.ModPapel), imshow(img);
        %   Modelo para o gesto: Tesoura
            img = imread('../Imagens Modelo/modelo_2.jpg');
            axes (handles.ModTesoura), imshow(img);
        %   Modelo para o gesto: Spock
            img = imread('../Imagens Modelo/modelo_3.jpg');
            axes (handles.ModSpock), imshow(img);
        %   Modelo para o gesto: Lagarto
            img = imread('../Imagens Modelo/modelo_4.jpg');
            axes (handles.ModLagarto), imshow(img);


    %%  Inicializando Trabalho
        %   Inicializando a WebCam Avulsa
            web = webcam (2);
        %   Armazenando o plano de fundo
            for ind = 0:2
                background = snapshot (web);
            end
        %   Mostrando captura de imagem da WebCam
            tentativas = 0;
        %   Enquanto não tiver ocorrido uma quantidade de erros de detecção
        %   da mão necessário para desistir, continue
            while (tentativas < 10)
            %   Capturam a provável imagem com a mão e exibindo-a
                mao = snapshot(web);
                axes (handles.ExibirWeb), imshow(mao);
                
            %   Segmentando a Mão e exibindo-a na interface
                [detectada, bordas, crct] = RealceMao (background, mao);
                axes (handles.ExibirJogada), imshow(bordas);
                
            %   Verificando se foi detectado alguma coisa na imagem
            %   Caso tenha sido detectada alguma coisa
                if (bordas ~= 0)
                    formato = DetectaForma (bordas, crct)
            %   Caso contrário, o formato já é configurado como
            %   'desconhecido'
                else
                    formato = 'desconhecido'
                end
                
            %   Sendo desconhecido, mais uma tentativa é computada
                if (formato ~= 'desconhecido')
                    break;
                end
            end


%img = imread('../Imagens Modelo/exemplo_web.jpg');
%axes (handles.ExibirWeb), imshow(img);
%img = imread('../Imagens Modelo/exemplo_jogada.jpg');
%axes (handles.ExibirJogada), imshow(img);
%img = imread('../Imagens Modelo/exemplo_jogada.jpg');
%axes (handles.ExibirJogada), imshow(img);
%img = imread('../Imagens Modelo/modelo_1.jpg');
%axes (handles.ExibirPC), imshow(img);
%set (handles.Acertou, 'visible', 'on');
%set (handles.Errou, 'visible', 'on');
%set (handles.LogJogada, 'visible', 'on');
%msg = sprintf('PERDEU! Pois...\nPAPEL cobre PEDRA');
%set (findobj(gcf, 'Tag', 'LogJogada'), 'String', msg, 'ForegroundColor', 'red');



% --- Executes on button press in Reiniciar.
function Reiniciar_Callback(hObject, eventdata, handles)
% hObject    handle to Reiniciar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
