// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� JNIDEMO_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// JNIDEMO_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef JNIDEMO_EXPORTS
#define JNIDEMO_API __declspec(dllexport)
#else
#define JNIDEMO_API __declspec(dllimport)
#endif

// �����Ǵ� JNIDemo.dll ������
class JNIDEMO_API CJNIDemo {
public:
	CJNIDemo(void);
	// TODO: �ڴ�������ķ�����
};

extern JNIDEMO_API int nJNIDemo;

JNIDEMO_API int fnJNIDemo(void);
